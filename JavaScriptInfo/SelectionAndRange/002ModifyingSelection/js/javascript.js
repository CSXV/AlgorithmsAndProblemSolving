button.onclick = function() {
  if (input.selectionStart == input.selectionEnd) return;

  let selected = input.value.slice(input.selectionStart, input.selectionEnd);
  input.setRangeText(`*${selected}*`);
}
