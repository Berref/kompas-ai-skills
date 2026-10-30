# ksWriteGroupToClip - Разместить группу в буфере обмена с удалением или оставлением геометрии в документе-источнике (скопировать или вырезать геометрию в буфер обмена)

[API экспортных функций](export_function.html) > [Редактирование графических объектов ](cn1712096.html) > [Функции редактирования объектов чертежа ](draft_edit_fncts_common.html) |  Scroll [ [ [ ](lightobj.html "К следующему разделу")](draft_edit_fncts_common.html "На уровень выше")](ksundocontainer.html "К предыдущему разделу")  
---|---  
  
[Пример...](kswritereadgroup_clip_example.html)

Аналог данной функции при использовании Automation - метод [ksDocument2D::ksWriteGroupToClip](ksdocument2d_kswritegrouptoclip.html).

Синтаксис:

int ksWriteGroupToClip (reference g, unsigned char copy);

Входные параметры:

g | \- указатель на группу,  
---|---  
copy | \- признак копирования или вырезания: 1 - копирование, 0 - вырезание.  
  
Возвращаемое значение:

1 | \- в случае успешного завершения,  
---|---  
0 | \- в случае неудачи.  
  
Подразделы:

(отсутствуют)
