const vueApp = Vue.createApp({
    data: function () {
        return {
            counter: 0
        }
    },
    methods: {
        incrementa: function () {
            this.counter++;
        },
        decrementa: function(){
            this.counter--;
        }
    }
})

vueApp.mount("#app");

/*
let counter = 0;

function incrementa(){
    counter++;
}

function apresenta() {
    const display = document.querySelector("#display");
    display.value = counter;
}

window.onload = () => {
    document.querySelector("button").onclick = () => {
        incrementa();
        apresenta();
    }
    apresenta();
}
*/

