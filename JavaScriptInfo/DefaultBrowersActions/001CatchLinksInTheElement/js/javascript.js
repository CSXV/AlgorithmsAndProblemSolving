contents.onclick = function(event) {
  function handleLink(href) {
    let isLeaving = confirm(`Leave to ${href}`);
    if (!isLeaving) return false;
  }

  let target = event.target.closest('a');
  if (target && contents.contains(target)) {
    return handleLink(target.getAttribute('href'));
  }
};


// my solution
// let field = document.getElementById('contents');
//
// field.addEventListener('click', function(event) {
//   let elem = event.target.closest('a');
//   if (elem.tagName != "A") return;
//
//   let href = elem.getAttribute('href');
//
//   let answer = confirm(`Leave to ${href}?`);
//   if (!answer)
//     event.preventDefault();
// });
