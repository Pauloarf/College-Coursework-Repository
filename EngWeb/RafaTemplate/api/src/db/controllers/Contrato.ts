import { type Model } from "mongoose";
import ContratoModel from "../models/Contrato.js";

type ExtractModelSchema<M> = M extends Model<infer X> ? X : never

async function getContratos(filter: ExtractModelSchema<typeof ContratoModel> = {}) {
    return ContratoModel.find(filter);
}

async function getSingleContrato(filter: ExtractModelSchema<typeof ContratoModel> = {}) {
    return ContratoModel.findOne(filter);
}

async function getDistinctContracts(filter: keyof ExtractModelSchema<typeof ContratoModel>) {
    return ContratoModel.distinct(filter);
}

async function createContrato(init: ExtractModelSchema<typeof ContratoModel>) {
    const contrato = new ContratoModel(init);
    await contrato.save();
}

async function killContrato(filter: ExtractModelSchema<typeof ContratoModel>) {
    await ContratoModel.deleteOne(filter);
}

export {
    getContratos,
    getSingleContrato,
    getDistinctContracts,
    createContrato,
    killContrato
};