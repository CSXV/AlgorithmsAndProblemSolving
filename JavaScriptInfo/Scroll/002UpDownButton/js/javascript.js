let arrowTop = document.getElementById('arrowTop');

arrowTop.onclick = function() {
  window.scrollTo(pageXOffset, 0);
};

window.addEventListener('scroll', function() {
  arrowTop.hidden = (pageYOffset < document.documentElement.clientHeight);
});

// my solution
// document.addEventListener('scroll', function(event) {
//   let documentBottom = document.documentElement.getBoundingClientRect().bottom;
//
//   if (documentBottom < document.documentElement.clientHeight / 2) {
//     arrowTop.style.display = 'block';
//   }
//
//   if (documentBottom > document.documentElement.clientHeight / 2) {
//     arrowTop.style.display = 'none';
//   }
//
//   arrowTop.onclick = function() {
//     window.scrollTo(0, 0);
//   };
//
// });
