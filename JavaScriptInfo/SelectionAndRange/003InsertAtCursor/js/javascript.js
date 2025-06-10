button.onclick = function () {
  input.setRangeText("Hello", input.selectionStart, input.selectionEnd, "end");
  input.focus();
};
