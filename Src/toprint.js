function toprint() {
    // zoom
    var zm = 100;
    document.body.style.zoom = String(zm) + '%';
    // hide
    arr = ['header', 'footer', 'sideBar', 'comment_form', 'blog_post_info_block', 'printButton'];
    for (var i of arr) {
        var ele = document.getElementById(i); if (ele == null) continue;
        ele.parentNode.removeChild(ele); console.log('deleted', i);
    }
    // width
    document.getElementById('home').style.overflow = 'hidden';
    document.getElementById('main').style.overflow = 'hidden';
    document.getElementById('home').style.width = '100%';
    document.getElementById('main').style.width = '100%';
    // content
    var cont = document.getElementById('mainContent');
    cont.style.width = '100%';
    cont.style.float = 'none';
    cont.style.border = 'none';
    cont.style.left = '-9px';
    cont.style.top = '-60px';
    // details
    const details = document.querySelectorAll("details");
    details.forEach((detail) => {
        detail.setAttribute("open", true);
    });
}
// event
function rdprint() { toprint(); setTimeout( function(){ if (!confirm("请等待网页公式加载完毕...")) return; setTimeout('window.print();', 150); }, 50); }