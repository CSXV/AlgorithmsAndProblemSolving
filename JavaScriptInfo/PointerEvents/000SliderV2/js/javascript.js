let thumb = document.querySelector(".thumb");

thumb.onpointerdown = function(event) {
  thumb.setPointerCapture(event.pointerId);

  thumb.onpointermove = function(event) {
    let newLeft = event.clientX - slider.getBoundingClientRect().left;
    if (newLeft < 0) newLeft = 0;

    let rightEdge = slider.offsetWidth - thumb.offsetWidth;
    if (newLeft > rightEdge) newLeft = rightEdge;

    text.innerText = newLeft;
    thumb.style.left = newLeft + "px";
  };

  thumb.onpointerup = function(event) {
    thumb.onpointermove = null;
    thumb.onpointerup = null;
  };
};
