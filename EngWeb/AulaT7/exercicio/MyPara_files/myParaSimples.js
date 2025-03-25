$("#addPara").click(function() {
    $("#paraList").append("<li><b>" + $("#date").text() + "</b>: " + 
        $("#paraText").val() + "</li>");
    $("#paraText").val("");
});