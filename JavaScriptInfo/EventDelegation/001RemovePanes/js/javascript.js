// container.addEventListener('click', function(event) {
//   if (event.target.className != 'remove-button') return;
//   let pane = event.target.closest('.pane');
//   pane.remove();
// });


// my solution
let buttons = document.querySelectorAll('.remove-button');

for (let button of buttons) {
  button.addEventListener('click', function(event) {
    let div = event.target.closest('.pane');

    if (!div) return;
    div.remove();
  });
}
