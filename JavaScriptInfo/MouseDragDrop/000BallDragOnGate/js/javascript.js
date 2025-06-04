let currentDroppable = null;

ball.onmousedown = function(event) {
  // mouse shift from ball
  let shiftX = event.clientX - ball.getBoundingClientRect().left;
  let shiftY = event.clientY - ball.getBoundingClientRect().top;

  // prepare for moving
  ball.style.position = 'absolute';
  ball.style.zIndex = 1000;

  // we move the element out of any parent
  document.body.append(ball);

  function moveAt(pageX, pageY) {
    ball.style.left = pageX - shiftX + "px";
    ball.style.top = pageY - shiftY + "px";
  }

  moveAt(event.pageX, event.pageY);

  function onMouseMove(event) {
    moveAt(event.pageX, event.pageY);

    // rapid change to capture element bellow the ball
    ball.hidden = true;
    let elemBelow = document.elementFromPoint(event.clientX, event.clientY);
    ball.hidden = false;

    if (!elemBelow) return;

    let droppableBelow = elemBelow.closest('.droppable');
    if (currentDroppable != droppableBelow) {
      if (currentDroppable) leaveDroppable(currentDroppable);

      currentDroppable = droppableBelow;
      if (currentDroppable) enterDroppable(currentDroppable);
    }
  }

  // move the ball on mouse move
  document.addEventListener('mousemove', onMouseMove);

  // drop the ball on mouse up
  ball.onmouseup = function() {
    document.removeEventListener('mousemove', onMouseMove);
    ball.onmouseup = null;
  }
};

// style the droppable
function enterDroppable(elem) {
  elem.style.background = 'pink';
}

function leaveDroppable(elem) {
  elem.style.background = '';
}

// disable browser own event
ball.ondragstart = function() {
  return false;
}
