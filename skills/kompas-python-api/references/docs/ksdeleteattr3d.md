# ksDeleteAttr3D - Удалить атрибут

[API экспортных функций](export_function.html) > [Функции работы с прикладной библиотекой ](cn1731963.html) > [Функции работы с атрибутами ](attribs_fncts_common.html) |  Scroll [ [ [ ](ksdeleteattr3dw.html "К следующему разделу")](attribs_fncts_common.html "На уровень выше")](ksdeleteattrrow.html "К предыдущему разделу")  
---|---  
  
Аналог данной функции при использовании Automation - метод [ksAttributeObject::ksDeleteAttr3D](ksattributeobject_ksdeleteattr3d.html).

Синтаксис:

int ksDeleteAttr3D (LPUNKNOWN pObj,

LPATTRIBUTE3D pAttr,

char* password);

Входные параметры:

[pObj](pobj.html) | \- указатель на объект, у которого удаляется атрибут,  
---|---  
pAttr | \- указатель на атрибут [IAttribute3D,](ksattribute3d.html)  
password | \- пароль.  
  
Возвращаемое значение:

1 | \- в случае удачного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
