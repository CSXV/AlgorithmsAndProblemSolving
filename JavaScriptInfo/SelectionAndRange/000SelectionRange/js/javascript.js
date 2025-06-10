button.onclick = function() {
  let range = new Range();

  range.setStart(p, start.value);
  range.setEnd(p, end.value);
  document.getSelection().removeAllRanges();
  document.getSelection().addRange(range);
}
