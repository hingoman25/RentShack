#include "firebase_cpp_sdk/include/firebase/database.h"
#include "firebase_cpp_sdk/include/firebase/app.h"


int main(){

	::firebase::AppOptions appOptions = ::firebase::AppOptions();

	appOptions.::firebase::AppOptions::set_app_id("rentshack-d2f8f");

	appOptions.::firebase::AppOptions::set_api_key("AIzaSyBApfToTzoqqENAUZkaoe75ArPH6OEqbgM");

	::firebase::AppOptions& appOptionsref = appOptions;

	::firebase::App* app = new ::firebase::App(appOptionsref);

	//::firebase::App* app = ::firebase::App::Create(appOptionsref);

	//app -> ::firebase::AppOptions::set_app_id("rentshack-d2f8f");

	//::firebase::database::Database* database = ::firebase::database::Database::GetInstance(app);
	::firebase::database::Database* database = new ::firebase::database::Database();
	database -> ::firebase::database::Database::GetInstance(app);

	// Get the root reference location of the database.
	/*firebase::database::DatabaseReference dbRef = database->GetReference();

	firebase::Future<firebase::database::DataSnapshot> result =
	    dbRef.GetReference().GetValue();*/

	return 0;

}