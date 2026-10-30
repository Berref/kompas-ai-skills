# CreateSubAssembly - Объединить в подсборку

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IParts7 ](iparts7.html) > [IParts7 - методы ](iparts7_methods.html) |  Scroll [ [ [ ](iparts7_findpart.html "К следующему разделу")](iparts7_methods.html "На уровень выше")](iparts7_createdocumentex.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iparts7.html)

Синтаксис Automation :

LPDISPATCH CreateSubAssembly( VARIANT Parts, BSTR FileName );

Синтаксис COM :

HRESULT CreateSubAssembly( VARIANT Parts, BSTR FileName, IPart7 * * Result );

Возвращаемое значение:

| \- Указатель на интерфейс новой вставки [IPart7](ipart7.html),  
---|---  
  
Входные параметры:

Parts | \- Список SafeArray VT_ARRAY | VT_DISPATCH перемещаемых в подсборку вставок [IPart7](ipart7.html),  
---|---  
FileName | \- Имя файла.  
  
Версия: Компас v20

Подразделы:

(отсутствуют)
