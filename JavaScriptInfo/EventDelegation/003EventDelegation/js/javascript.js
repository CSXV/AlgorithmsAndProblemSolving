let grid = document.getElementById("grid");

grid.onclick = function (event) {
  let th = event.target;

  if (th.tagName != "TH") return;

  sort(th.cellIndex, th.dataset.type);
};

function sort(colNum, type) {
  let tbody = grid.querySelector("tbody");

  let rowsArray = Array.from(tbody.rows);

  // compare(a, b) compares two rows, need for sorting
  let compare;

  switch (type) {
    case "number":
      compare = function (rowA, rowB) {
        return rowA.cells[colNum].innerHTML - rowB.cells[colNum].innerHTML;
      };
      break;

    case "string":
      compare = function (rowA, rowB) {
        return rowA.cells[colNum].innerHTML > rowB.cells[colNum].innerHTML
          ? 1
          : -1;
      };
      break;
  }

  // sort
  rowsArray.sort(compare);

  tbody.append(...rowsArray);
}
