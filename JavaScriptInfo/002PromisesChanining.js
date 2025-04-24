function json() {
  return Promise.resolve(JSON.parse(`{ "name": "CSXV" }`));
}

function loadJSON(url) {
  return fetch(url).then((response) => response.json());
}

function loadGitHubUser(name) {
  return loadJSON(`https://api.github.com/users/${name}`);
}

function ShowInfo(githubUser) {
  let name = document.createElement("h2");
  name.innerText = githubUser.login;
  name.className = "promise-name-example";
  document.body.append(name);

  let id = document.createElement("p");
  id.innerText = githubUser.id;
  document.body.append(id);

  let img = document.createElement("img");
  img.src = githubUser.avatar_url;
  img.className = "promise-avatar-example";
  document.body.append(img);
}

json()
  .then((user) => loadGitHubUser(user.name))
  .then(ShowInfo);
