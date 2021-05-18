static int _offset = 0;

int initialParamOffset()
{
    return 1;
}

int initialVarOffset()
{
    return -1;
}

void startOffsets(int v)
{
    _offset = v;
}

int nextParamOffset(int size)
{
    int save = _offset;
    _offset += size;
    return save;
}

int nextVarOffset(int size)
{
    _offset -= size;
    return _offset;
}

int getMaxOffset()
{
    return _offset;
}
