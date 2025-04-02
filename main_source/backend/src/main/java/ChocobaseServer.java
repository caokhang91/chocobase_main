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
                }
                if ("/ask".equals(req.path())) {
                    // req.bodyHandler(body -> {
                    //     String prompt = body.toJsonObject().getString("prompt");

                    //     JsonObject payload = new JsonObject()
                    //     .put("model", "gpt-3.5-turbo")
                    //     .put("messages", new io.vertx.core.json.JsonArray()
                    //         .add(new JsonObject()
                    //         .put("role", "user")
                    //         .put("content", prompt)));

                    //     client.post(443, "api.openai.com", "/v1/chat/completions")
                    //     .putHeader("Authorization", "Bearer YOUR_API_KEY_HERE")
                    //     .putHeader("Content-Type", "application/json")
                    //     .ssl(true)
                    //     .sendJsonObject(payload, ar -> {
                    //         if (ar.succeeded()) {
                    //         String responseText = ar.result().bodyAsJsonObject()
                    //             .getJsonArray("choices")
                    //             .getJsonObject(0)
                    //             .getJsonObject("message")
                    //             .getString("content");
                    //         req.response().putHeader("Content-Type", "text/plain")
                    //             .end(responseText);
                    //         } else {
                    //         req.response().setStatusCode(500).end("OpenAI error");
                    //         }
                    //     });
                    // });
                } else {
                    req.response().end("Hello from Chocobase backend");
                }
                if("/test".equals(req.path())){

                }else {
                    req.response().end("Hello from Chocobase");
                }
            })
            .listen(8080);
    }
}
