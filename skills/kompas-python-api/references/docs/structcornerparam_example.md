# Пример использования структуры параметров CornerParamи массива CORNER_ARR

» Нет разделов более высокого уровня « |  Scroll  
---|---  
  
reference arr = ::CreateArray (CORNER_ARR, 0); // создать массив параметров углов

CornerParam par; // структура параметров угла

par.index = 5; // индекс угла

par.fillet = 0; // признак фаски

par.l1 = 345; // длина фаски 1 сегмента

par.l2 = 456.987; // длина фаски 2 сегмента

::AddArrayItem (arr, -1, &par, sizeof (CornerParam)); // добавить угол в массив

par.index = 45; // индекс угла

par.fillet = 0; // признак фаски

par.l1 = 345; // длина фаски 1 сегмента

par.l2 = 456.987; // длина фаски 2 сегмента

::AddArrayItem (arr, -1, &par, sizeof (CornerParam));// добавить угол в массив

par.index = 65; // индекс угла

par.fillet = 0; // признак фаски

par.l1 = 345; // длина фаски 1 сегмента

par.l2 = 456.987; // длина фаски 2 сегмента

::AddArrayItem (arr, -1, &par, sizeof (CornerParam));// добавить угол в массив

par.index = 85; // индекс угла

par.fillet = 0; // признак фаски

par.l1 = 345; // длина фаски 1 сегмента

par.l2 = 456.987; // длина фаски 2 сегмента

::AddArrayItem (arr, -1, &par, sizeof (CornerParam));// добавить угол в массив

int count = ::GetArrayCount (arr); // количество элементов в массиве

for ( int i = 0; i < count; i ) {

// выводим параметры углов в окне сообщения

char buf[128];

if ( ::GetArrayItem (arr, i, &par, sizeof (CornerParam))) {

::sprintf ( buf, "индекс элемента %i равен %i; %i, %f, %f", i,

par.index, par.fillet, par.l1, par.l2);

::Message (buf);

}

}

::ExcludeArrayItem (arr, 2); // удаляем второй элемент массива

count = ::GetArrayCount (arr); // количество элементов в массиве

for ( int i = 0; i < count; i ) {

// выводим параметры углов в окне сообщения

char buf [128];

if ( ::GetArrayItem (arr, i, &par, sizeof (CornerParam))) {

::sprintf (buf, "индекс элемента %i равен %i; %i, %f, %f", i, par.index,

par.fillet, par.l1, par.l2 );

::Message( buf );

}

}

if ( ::GetArrayItem (arr, 1, &par, sizeof (CornerParam))) {

// изменяем параметры элемента с индексом 1

par.index = 0;

par.fillet = 0;

par.l1 = 0;

par.l2 = 0;

::SetArrayItem( arr, 1, &par, sizeof(CornerParam) );

}

count = ::GetArrayCount (arr); // количество элементов в массиве

for ( int i = 0; i < count; i ) {

// выводим параметры углов в окне сообщения

char buf[128];

if ( ::GetArrayItem (arr, i, &par, sizeof (CornerParam))) {

::sprintf (buf, "индекс элемента %i равен %i; %i, %f, %f", i, par.index,

par.fillet, par.l1, par.l2);

::Message( buf );

}

}

::ClearArray (arr); // очищаем массив

char buf[128];

::sprintf (buf, "кол-во элементов = %i", ::GetArrayCount (arr));

::Message (buf);

::DeleteArray (arr); // удаляем массив
