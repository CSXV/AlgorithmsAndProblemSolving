for (let li of tree.querySelectorAll('li')) {
  let span = document.createElement('span');

  li.prepend(span);
  span.append(span.nextSibling); // move the text node into span
}

// catch clicks on whole tree
tree.onclick = function(event) {

  if (event.target.tagName != 'SPAN') {
    return;
  }

  let childrenContainer = event.target.parentNode.querySelector('ul');
  if (!childrenContainer) return; // no children

  childrenContainer.hidden = !childrenContainer.hidden;
}

// my solution
// tree = document.getElementById('tree');
//
// tree.addEventListener('click', function(event) {
//   let elem = event.target;
//
//   if (elem.tagName != 'LI') return;
//
//   hide(elem);
// });

// function hide(li) {
//   let childrens = li.querySelectorAll('li');
//
//   for (let child of childrens) {
//     child.hidden = !child.hidden;
//   }
// }
