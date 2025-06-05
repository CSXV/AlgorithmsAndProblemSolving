let menuDiv = document.getElementById('menu-div');
let menuHead = document.getElementById('menu-head');


menuHead.onclick = function showMenu() {
  menuDiv.classList.toggle('open')
}
