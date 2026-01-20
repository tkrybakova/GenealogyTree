function loadPersons() {
    fetch('/persons')
        .then(response => response.json())
        .then(data => {
            const ul = document.getElementById('persons');
            ul.innerHTML = ''; // очистить список
            data.forEach(person => {
                const li = document.createElement('li');
                li.textContent = person.firstName + " " + person.lastName;
                ul.appendChild(li);
            });
        })
        .catch(err => console.error(err));
}
