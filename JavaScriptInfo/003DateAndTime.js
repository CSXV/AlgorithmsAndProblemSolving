// Create a function getDateAgo(date, days) to return the day of month days ago from the date.

let date = new Date(2015, 0, 2);

function getDateAgo(date, days) {
  let newDate = new Date(date);

  newDate.setDate(date.getDate() - days);
  return newDate.getDate();
}

alert(getDateAgo(date, 1));
alert(getDateAgo(date, 2));
alert(getDateAgo(date, 365));
