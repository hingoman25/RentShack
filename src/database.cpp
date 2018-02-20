#include "firebase/app.h"

::firebase::database::Database *database = ::firebase::database::Database::GetInstance(app);

// Get the root reference location of the database.
firebase::database::DatabaseReference dbref = database->GetReference();

firebase::Future<firebase::database::DataSnapshot> result =
    dbRef.GetReference("posts").GetValue();

