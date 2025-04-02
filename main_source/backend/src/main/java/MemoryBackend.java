import io.vertx.core.AbstractVerticle;
import io.vertx.core.Vertx;
import io.vertx.core.json.JsonObject;
import io.vertx.ext.web.Router;
import io.vertx.ext.web.handler.BodyHandler;

import java.sql.*;
import java.time.LocalDateTime;

public class MemoryBackend extends AbstractVerticle {
    private Connection conn;

    @Override
    public void start() throws Exception {
        conn = DriverManager.getConnection("jdbc:sqlite:npc_memory.db");

        try (Statement st = conn.createStatement()) {
            st.execute("CREATE TABLE IF NOT EXISTS memory (id INTEGER PRIMARY KEY AUTOINCREMENT, npc_id TEXT, timestamp TEXT, role TEXT, message TEXT)");
        }

        Router router = Router.router(vertx);
        router.route().handler(BodyHandler.create());

        router.post("/memory").handler(ctx -> {
            JsonObject body = ctx.getBodyAsJson();
            try (PreparedStatement ps = conn.prepareStatement("INSERT INTO memory (npc_id, timestamp, role, message) VALUES (?, ?, ?, ?)")) {
                ps.setString(1, body.getString("npc_id"));
                ps.setString(2, LocalDateTime.now().toString());
                ps.setString(3, body.getString("role"));
                ps.setString(4, body.getString("message"));
                ps.executeUpdate();
                ctx.response().end("OK");
            } catch (Exception e) {
                ctx.response().setStatusCode(500).end("DB error");
            }
        });

        vertx.createHttpServer().requestHandler(router).listen(8080);
        System.out.println("✅ Backend Memory API on http://localhost:8080");
    }

    public static void main(String[] args) {
        Vertx.vertx().deployVerticle(new MemoryBackend());
    }
}
