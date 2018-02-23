'use strict';


var itemList = document.getElementById("itemList");
var input = document.getElementById("query");
var arr =[];

function snapshotToArray(snapshot) {
    var returnArr = [];

    snapshot.forEach(function(childSnapshot) {
        var item = childSnapshot.val();
        item.key = childSnapshot.key;

        returnArr.push(item);
        arr.push(item);
    });
    return returnArr;
}

function findMatches(wordToMatch, arr) {

    return arr.filter(e => {
        const regex = new RegExp(wordToMatch, 'gi');
        return e.titlePost.match(regex); 
    });
    
}

function displayMatches() {
    var matchArray = findMatches(this.value, arr);
    var html = matchArray.map(e => {
        return `
            <li>
                <a style="text-decoration:none" href="../itemPage/itemPage.html?pid=${e.pid}">
                    <span class="title">${e.titlePost}</span>
                </a>
            </li>
        `;
    }).join('');
    if(searchInput != "") {
        suggestions.innerHTML = html;    
    }
}


var searchInput = document.querySelector('.search');
var suggestions = document.querySelector('.suggestions');

searchInput.addEventListener('change', displayMatches);
searchInput.addEventListener('keyup', displayMatches);























// firebase.database().ref('/posts').on('value', function(snapshot) {
   
//     var arr = snapshotToArray(snapshot);
//     itemList.innerHTML = "";
//     arr.forEach(function(e){

//         itemList.innerHTML += 
//             '<a style="text-decoration:none" style="display:block" href="../itemPage/itemPage.html?pid=' + e.pid + '">' +
//                     '<option>' + e.titlePost + '</option>' +
//             '</a>';
//     });   
// });




