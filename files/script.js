const form = document.getElementById('form1')
form.addEventListener('submit', (e) => {
  e.preventDefault()
  const formData = new FormData(form)
  const name = formData.get('name')
  const surname = formData.get('surname')

  console.log(name + '|' + surname)
});

