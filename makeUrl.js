const allLinks = document.getElementsByTagName("li")
let i=0;

for (link of allLinks){
    const msg = `<li><a href="https://www.${link.innerText}">${link.innerText}</a><input id="button${i}" type="checkbox" name="done${i}"></li>`;
    link.outerHTML=msg;
    ++i;
    checkbox=document.getElementById(`button${i}`);

    //link.innerHTML=`<li><a href="${link.innerText}">${link.innerText}</a></li>`
}

// function saveCheck(checkbox){
//     localStorage.setItem(`button${i}`, checkbox.checked);
// }

// function loadCheck(i){
//     let checked = JSON.parse(localStorage.getItem(`button${i}`));
//     document.getElementById(`button${i}`).checked = checked;
// } checkbox는 checked의 값이 변해서 알 수 있음.
