document.addEventListener("DOMContentLoaded", function () {
    document.querySelectorAll("a").forEach((link) => {
        console.log("LINK:", link, link.href)
        if (link.href === window.location.href.replace(window.location.search, "")) {
            link.classList.add("current");
        // } else if (window.location.href.replace(window.location.search, "").includes(`/${link.href.replace(/oes$/, "ao")}/`)) {
        } else if (window.location.href.replace(window.location.search, "").includes(link.href.replace(/oes$/, "ao"))) {
            link.classList.add("current");
        }
    });
});