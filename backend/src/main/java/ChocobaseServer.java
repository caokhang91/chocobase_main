import io.vertx.core.AbstractVerticle;
import io.vertx.core.Vertx;

public class ChocobaseServer extends AbstractVerticle {
    public static void main(String[] args) {
        Vertx.vertx().deployVerticle(new ChocobaseServer());
    }

    @Override
    public void start() {
        vertx.createHttpServer()
            .requestHandler(req -> {
                if ("/ping".equals(req.path())) {
                    req.response().end("pong from Chocobase backend 🚀");
                } else {
                    req.response().end("Hello from Chocobase");
                }
            })
            .listen(8080);
    }
}
