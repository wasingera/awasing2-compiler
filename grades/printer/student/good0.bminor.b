x: array[10] integer = {1, 2, 3, 4, 5};
f: function boolean (s: string, z: string) = {
    if (s == z)
        return true;
    else
    {
        print "bad!";
        return false;
    }

}