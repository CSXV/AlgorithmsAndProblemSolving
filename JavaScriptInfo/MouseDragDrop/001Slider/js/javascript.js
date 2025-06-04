let slider = document.getElementById('slider');
let thumb = document.querySelector('.thumb');

thumb.onmousedown = function(event) {
  let shiftX = event.clientX - thumb.getBoundingClientRect().left;

  document.addEventListener('mousemove', onMouseMove);
  document.addEventListener('mouseup', onMouseUp);

  // my solution [[[--------
  // let max = slider.getBoundingClientRect().width;
  // let min = slider.getBoundingClientRect().y

  // function moveAt(pageX) {
  //   // for debug
  //
  //   if (thumb.getBoundingClientRect().left > max) {
  //     thumb.style.left = max;
  //     return;
  //   }
  //
  //   if (thumb.getBoundingClientRect().left < min) {
  //     thumb.style.left = min;
  //     return;
  //   }
  //
  //   thumb.style.left = pageX - shiftX - 10 + "px";
  // }
  // --------]]]

  function onMouseMove(event) {
    // moveAt(event.pageX, event.pageY);

    let newLeft = event.clientX - shiftX - slider.getBoundingClientRect().left;
    if (newLeft < 0) newLeft = 0;

    let rightEdge = slider.offsetWidth - thumb.offsetWidth;
    if (newLeft > rightEdge) newLeft = rightEdge;

    text.innerText = newLeft;
    thumb.style.left = newLeft + 'px';
  }

  function onMouseUp() {
    document.removeEventListener('mouseup', onMouseUp);
    document.removeEventListener('mousemove', onMouseMove);
  }

};

thumb.ondragstart = function() {
  return false;
}
