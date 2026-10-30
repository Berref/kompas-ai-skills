# ksIsLibraryProductKeyInfoW - Получить информацию о текущей сессии (Unicode)

[API экспортных функций](export_function.html) > [Функции работы с документами ](docum_fncts_common.html) > [Сервисные функции ](serv_fncts_common.html) |  Scroll [ [ [ ](ksislibraryproductname.html "К следующему разделу")](serv_fncts_common.html "На уровень выше")](ksislibraryproductkeyinfo.html "К предыдущему разделу")  
---|---  
  
Синтаксис:

int LIB_FUNC ksIsLibraryProductKeyInfoW( unsigned int prodNumb, LPWSTR keyInfo, int keyInfoLen );

Входные параметры:

prodNumb | \- номер продукта,  
---|---  
keyInfoLen | \- размер буфера.  
  
Выходной параметр:

keyInfo | \- буфер для информации о текущей сессии.  
---|---  
  
Возвращаемое значение

TRUE | \- в случае успешного завершения.  
---|---  
  
Подразделы:

(отсутствуют)
