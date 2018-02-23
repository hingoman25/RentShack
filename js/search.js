'use strict';


var itemList = document.getElementById("itemList");


function snapshotToArray(snapshot) {
    var returnArr = [];

    snapshot.forEach(function(childSnapshot) {
        var item = childSnapshot.val();
        item.key = childSnapshot.key;

        returnArr.push(item);
    });

    return returnArr;
}

document.getElementById('anchor').addEventListener("click", sendInstancePID() );

function sendInstancePID() {
    alert("THIS IS A FUCKING MESSAGE");
}

firebase.database().ref('/posts').on('value', function(snapshot) {
    var arr = snapshotToArray(snapshot);

    itemList.innerHTML = "";
    arr.forEach(function(e){
    	itemList.innerHTML += 
		   '<a id="anchor" style="text-decoration: none" style="display:block" href="itemPage/itemPage.html?pid=' + e.pid + '">' +
					'<option>' + e.titlePost + '</option>' +
			'</a>';

    });
});

// "../itemPage/itemPage.html?pid=' + pid + '"