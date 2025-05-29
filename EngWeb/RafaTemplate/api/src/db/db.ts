import mongoose from "mongoose";

const CONNECTION = process.env.MONGO_URI ?? "mongodb://127.0.0.1:27018/contratos";

let _db: mongoose.Connection | undefined;
async function connect(): Promise<mongoose.Connection> {
    return new Promise((resolve, reject) => {
        console.log(`Attempting connection to ${CONNECTION}...`);
        mongoose.connect(CONNECTION);
        
        const db = mongoose.connection;
        db.on("error", (e) => {
            console.error("[MONGODB]", e);
            reject();
        });
        db.on("open", () => {
            console.log("Successfully connected to the database");
            resolve(db);
        });
    });
}

async function getDB(): Promise<mongoose.Connection> {
    if (_db === undefined) {
        _db = await connect();
    }

    return _db;
}

export {
    connect,
    getDB
};