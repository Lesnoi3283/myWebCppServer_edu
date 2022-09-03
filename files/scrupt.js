const form2 = document.getElementById('form2')
form2.addEventListener('submit', (e) => {
  e.preventDefault()
  const formData2 = new FormData(form2)

  const messages = formData2.get('messages')

  console.log(messages)
});