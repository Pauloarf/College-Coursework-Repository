import mongoose, { Schema } from "mongoose";

const ContratoSchema = new Schema(
    {
        idcontrato: String,
        nAnuncio: String,
        tipoprocedimento: String,
        objectoContrato: String,
        dataPublicacao: String,
        dataCelebracaoContrato: String,
        precoContratual: String,
        prazoExecucao: String,
        NIPC_entidade_comunicante: String,
        entidade_comunicante: String,
        fundamentacao: String,
    },
    // { strict: false }
);
const ContratoModel = mongoose.model("Contrato", ContratoSchema, "contratos");
// const ContratoModel = mongoose.model("Contrato", {}, "contratos");

export default ContratoModel;