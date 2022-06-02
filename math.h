// -----------------------------------------------------------------------------
// GEOMETRIC FUNCTIONS
// -----------------------------------------------------------------------------

// -------------------- Cartesian Radius Checker Function --------------------
int canInteract(int x1,int y1,int x2,int y2)
{
    int i = isLessThan((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2),(INTERACT_DISTANCE*INTERACT_DISTANCE));

    return i;
}
