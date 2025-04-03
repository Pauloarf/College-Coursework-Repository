$(function(){
    let paraCount= 0;
    // Carregar os paragrafos existentes na base de dados.
    $.get('http://localhost:3000/paras', async function(plist){
        try {
            paraCount = plist.length;
            plist.forEach(p => {
                $("#paraList").append(
                    `<li "p_id"="${p.id}">
                        <b>${p.date}</b>: ${p.p}
                        <button class="w3-button w3-red w3-small w3-round-large w3-right removeB">DELETE ME</button>
                    </li>`
                )
            })
        } catch (err) {
            console.log('Error fetching paras');
        }
    });

    // Adicionar novo parágrafo
    $("#addPara").click(() => {
        let text = $("#paraText").val();
        let nDate = new Date();
        let date = nDate.toISOString().substring(0,19);
        let newpara = {
            p: text,
            date: date,
            id: "p" + paraCount
        }
        $.post({
            url: "http://localhost:3000/paras",
            data: JSON.stringify(newpara),
            headers: {'Content-Type': 'application/json'},
            dataType: 'json',
            success: function(response){
                alert('Registo inserido com sucesso na BD!\n' + JSON.stringify(response));
                $("#paraList").append(
                    `<li "p_id"="${newpara.id}">
                        <b>${newpara.date}</b>: ${newpara.p}
                        <button class="w3-button w3-red w3-small w3-round-large w3-right removeB">DELETE ME</button>
                    </li>`
                )
                paraCount++;
            },
            error: (error) => {
                alert('OCORREU UM ERRO!\n' + JSON.stringify(error));
            }
        })
    })

    $("#paraList").on("click", ".removeB", () => {
        let li = $(this).parent();
        let paraId = li.attr("p_id");

        alert(`teste ${JSON.stringify(paraId)}`)

        $.ajax({
            url: `http://localhost:3000/paras/${paraId}`,
            type: 'DELETE',
            success: function(response) {
                li.remove()
            },
            error: (error) => {
                alert("Erro ao apagar: " + JSON.stringify(error))
            }
        })
    })
})