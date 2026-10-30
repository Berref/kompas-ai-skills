# FindPart - Возвращает компонент по ключу информационного объекта

[API интерфейсов. Версия 7](applicate.html) > [Документ 3D ](bc1473974.html) > [Компоненты ](bc2609111.html) > [Интерфейс IParts7 ](iparts7.html) > [IParts7 - методы ](iparts7_methods.html) |  Scroll [ [ [ ](iparts7_moveparts.html "К следующему разделу")](iparts7_methods.html "На уровень выше")](iparts7_createsubassembly.html "К предыдущему разделу")  
---|---  
  
[Интерфейс...](iparts7.html)

Синтаксис Automation :

LPDISPATCH FindPart( BSTR UniqueMetaObjectKey, BOOL Reqursive );

Синтаксис COM:

HRESULT FindPart( BSTR UniqueMetaObjectKey, BOOL Reqursive, IPart7 * * Result );

Возвращаемое значение:

| \- Указатель на интерфейс [IPart7](ipart7.html),  
---|---  
  
Входные параметры:

UniqueMetaObjectKey | \- Уникальный ключ информационного объекта,  
---|---  
Reqursive | \- Признак необходимости поиска в глубину.  
  
Версия: Компас v20

Подразделы:

(отсутствуют)
