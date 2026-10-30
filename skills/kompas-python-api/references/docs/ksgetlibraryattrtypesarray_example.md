# ksGetLibraryAttrTypesArray - Пример использования

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
//получим массив типов атрибутов в spc.lat

reference typeArr = ksGetLibraryAttrTypesArray(("d:\\\0\\\Spc.lat")); // полное имя библиотеки стилей

if (typeArr) {

char buf[128];

//определим количество типов и отобразим на экране

int count = GetArrayCount(typeArr);

sprintf(buf, "count = %d", count);

Message(buf);

//в цикле получим информацию о каждом типе и отобразим на экране

for (uint i = 0; i < count; i) {

LibraryAttrTypeParam par;

GetArrayItem(typeArr, // указатель на массив

i, // индекс в массиве (нумерация начинается с 0)

&par, // указатель на структуру элемента

sizeof(LibraryAttrTypeParam)); // размер структуры элемента

sprintf(buf, "ID = %f\nname=%s", par.typeId, par.name);

Message(buf);

}

}
