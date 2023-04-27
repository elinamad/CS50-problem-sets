window.addEventListener("load", function() {
    var f = document.getElementById('text');
    setInterval(function() {
        f.style.display = (f.style.display == 'none' ? '' : 'none');
    }, 200);

}, false);