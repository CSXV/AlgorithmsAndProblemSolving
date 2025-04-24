fetch(`https://api.github.com/users/CSXV`)
  .then((response) => response.json())
  .then((githubUser) => {
    let name = document.createElement("h2");
    name.innerText = githubUser.login;
    name.className = "promise-name-example";
    document.body.append(name);

    let id = document.createElement("p");
    id.innerText = githubUser.id;
    id.classid = "promise-id-example";
    document.body.append(id);

    let img = document.createElement("img");
    img.src = githubUser.avatar_url;
    img.className = "promise-avatar-example";
    document.body.append(img);
  });
