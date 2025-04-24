// Write the code to select the element with data-widget-name attribute from the document and to read its value.

let elem = document.querySelector(`[data-widget-name]`);

alert(elem.dataset.widgetName);
// or
alert(elem.getAttribute("data-widget-name"));
