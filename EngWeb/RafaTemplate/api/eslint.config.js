import eslint from "@eslint/js";
import tseslint from "typescript-eslint";

const config = tseslint.config(
    {
        ignores: ["**/node_modules", "**/dist", "**/public"],
    },
    eslint.configs.recommended,
    tseslint.configs.recommended,
    {
        rules: {
            semi: ["error", "always"],

            indent: ["error", 4, {
                SwitchCase: 1,
            }],

            quotes: ["error", "double", {
                allowTemplateLiterals: true,
            }],

            "@typescript-eslint/explicit-member-accessibility": ["error", {
                accessibility: "explicit",

                overrides: {
                    accessors: "off",
                    constructors: "off",
                    methods: "explicit",
                    properties: "explicit",
                    parameterProperties: "off",
                },
            }],

            "@typescript-eslint/explicit-function-return-type": ["error", {
                allowExpressions: true,
                allowTypedFunctionExpressions: true,
                allowHigherOrderFunctions: true,
                allowDirectConstAssertionInArrowFunctions: false,
                allowConciseArrowFunctionExpressionsStartingWithVoid: false,
                allowFunctionsWithoutTypeParameters: true,
                allowedNames: [],
                allowIIFEs: true,
            }],

            "@typescript-eslint/no-unused-vars": ["error", {
                args: "all",
                argsIgnorePattern: "^_",
                caughtErrors: "all",
                caughtErrorsIgnorePattern: "^_",
                destructuredArrayIgnorePattern: "^_",
                varsIgnorePattern: "^_",
                ignoreRestSiblings: true,
            }],
        },
    }
);

// console.log("ESLINT FUCKING CONFIG:", config);

export default config;