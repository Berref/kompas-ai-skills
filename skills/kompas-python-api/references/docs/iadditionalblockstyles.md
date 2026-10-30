# Интерфейс IAdditionalBlockStyles

[API интерфейсов. Версия 7](applicate.html) > [Работа со спецификацией ](spec_work.html) |  Scroll [ [ [ ](iadditionalblockstyles_props.html "К следующему разделу")](spec_work.html "На уровень выше")](iadditionalblocksectiontunings_item.html "К предыдущему разделу")  
---|---  
  
Интерфейс коллекции стилей блоков дополнительных (вложенных) разделов.

Иерархия:

[IKompasAPIObject](ikompasapiobject.html)

[IKompasCollection](ikompascollection.html)

[IAdditionalBlockStyles](iadditionalblockstyles.html)

Описание:

Управляет массивом интерфейсов [IAdditionalBlockStyle](iadditionalblockstyle.html).

Блоки разделов бывают вложенными и дополнительными. Вложенные блоки разделов располагаются внутри раздела, после всех объектов этого раздела.

Дополнительные блоки разделов располагаются в конце спецификации, после всех ее разделов.

Примечание:

Данный интерфейс может быть получен от интерфейса стиля спецификации [ISpecificationStyle](ispecificationstyle.html) с помощью свойства [ISpecificationStyle::AdditionalBlocks](ispecificationstyle_additionalblocks.html).

Подразделы:

[IAdditionalBlockStyles - свойства ](iadditionalblockstyles_props.html)
