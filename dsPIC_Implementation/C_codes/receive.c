uint8_t check(uint8_t *data)
{
    if(data[0]==36)
        return data;
    else
        return 78;
}
