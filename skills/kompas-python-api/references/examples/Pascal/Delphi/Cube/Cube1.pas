////////////////////////////////////////////////////////////////////////////////
//
// Пример библиотеки с пользовательской панелью
//
////////////////////////////////////////////////////////////////////////////////
unit Cube1;

interface
uses
  LDefin2D, ksAuto, Libtool, Windows, ks3DCOM_TLB, LDefin3D, LTool3D;

////////////////////////////////////////////////////////////////////////////////

  procedure  LIBRARYENTRY( command: WORD  ); stdcall;
  function   LIBRARYID   : Cardinal;         stdcall;
  procedure  MyDLLProc(Reason: Integer);

  function   LoadStr_( ID : Integer ) : string;                     // Загрузка строки из ресурсов
  function   LibMessage( str : string; flags : integer ) : Integer;// Выдача сообщения библиотеки
  function   LibMessageByID( strId, flags : Integer ) : Integer;   // Выдача сообщения библиотеки
  procedure  GetNewKompasAPI;
  procedure  TestOpenGL;
  procedure  TestOpenGLForCurrentDoc( regrawType : Integer );

implementation

uses
  LtDefine,
  cBaseEvents,
  DocumentFrameEvents,
  ksConstTLB,
  forms,
{$IFDEF __LIGHT_VERSION__}
  klAPI7;
{$ELSE}
  ksApi7;
{$ENDIF}

var
  newKompasAPI : IApplication;                                // Компас Application 7


//------------------------------------------------------------------------------
// LibraryName
//---
procedure MyDLLProc(Reason: Integer);
begin
  if Reason = DLL_PROCESS_DETACH then begin
    cBaseEvent.TerminateEvents;
    newKompasAPI       := nil;
    Application.Handle := 0;
  end;
end;

//------------------------------------------------------------------------------
// LibraryId
//---
function LIBRARYID: UINT; stdcall;
begin
  Result := 100;  // IDR_LIB
end;

//------------------------------------------------------------------------------
// LibraryEntry
//---
procedure LIBRARYENTRY( command: WORD ); stdcall;
begin
  Application.Handle := GetHWindow;

  case command of
    1 : begin TestOpenGL(); end;                                 // Кубик
    2, 3, 4, 5: begin TestOpenGLForCurrentDoc( command - 2 ); end;  // Тесты для текущего документа
  end;
end;

//------------------------------------------------------------------------------
// Получить доступ к новому API
// ---
procedure GetNewKompasAPI;
  var
    disp : IDispatch;
begin
	if newKompasAPI = nil then
  begin
    disp := IDispatch( CreateKompasApplication );
    newKompasAPI := disp As IApplication;
  end
end;

//------------------------------------------------------------------------------
// Зогрузить строку из ресурсов
//---
function LoadStr_( ID : Integer ) : string;
var
  buf : array [0..255] of AnsiChar;
begin
  ksConvertLangStrEx( hInstance, ID, buf, 255 );
  Result := buf;
end;

//------------------------------------------------------------------------------
// Вывод сообщения
// ---
function LibMessage( str : string; flags : integer ) : Integer;
var
 enabse : Integer;
begin
  enabse := IsEnableTaskAccess();  // проверка доступа
  if enabse <> 0 then              // если доступ к задаче разрешен
    EnableTaskAccess(0);           // запрещаем доступ

    //                         текст сообщения  заголовок          параметры
  Result := Application.MessageBox( PChar(str), PChar(LoadStr_(LIBRARYID)), flags );

  if enabse <> 0 then                 // если доступ к задаче был запрещен
    EnableTaskAccess(1);              // разрешаем доступ к задаче


end;

//------------------------------------------------------------------------------
// Вывод сообщения
// ---
function LibMessageByID( strId, flags : Integer ) : Integer;
begin
  Result := LibMessage( LoadStr_(strId), flags );
end;

//------------------------------------------------------------------------------
// Оперция выдавливания, работа с экизом
// ---
function CreateExtrusion( var part : IPart ) : boolean;
var
  iunkn              : IUnknown;
  entitySketch,
  basePlane,
  entityExtrusion    : IEntity;
  sketchDefinition   : ISketchDefinition;
  extrusionDefinition: IBossExtrusionDefinition;

begin
  Result := FALSE;
  // Создадим новый эскиз
  entitySketch := IEntity(part.NewEntity( o3d_sketch ));
  if entitySketch <> nil then
  begin
    entitySketch._Release;
    // Получить указатель на интерфейс параметров объектов и элементов
    iunkn := IUnknown( entitySketch.GetDefinition() );
//    iunkn.QueryInterface( IID_ISketchDefinition, sketchDefinition );
    sketchDefinition := iunkn As ISketchDefinition;
    if sketchDefinition <> nil then
    begin
      iunkn._Release;
      // Получим интерфейс базовой плоскости XOY
      basePlane := IEntity( part.GetDefaultEntity( o3d_planeXOY ) );
      if basePlane <> nil then
      begin
        basePlane._Release;
        // Установка параметров эскиза
        sketchDefinition.SetPlane( basePlane ); // Установим плоскость XOY базовой для эскиза
        sketchDefinition.SetAngle( 45 );        // Угол поворота эскиза

        // Создадим эскиз
        entitySketch.Create();

        // Войти в режим редактирования эскиза
        if sketchDefinition.BeginEdit() <> 0 then
        begin
          // Введем новый эскиз - квадрат
          LineSeg(  50,  50, -50,  50, 1 );
          LineSeg(  50, -50, -50, -50, 1 );
          LineSeg(  50, -50,  50,  50, 1 );
          LineSeg( -50, -50, -50,  50, 1 );
          // Выйти из режима редактирования эскиза
          sketchDefinition.EndEdit();
        end;
        // Оперция выдавливани
        entityExtrusion := IEntity( part.NewEntity( o3d_bossExtrusion ) );
        if entityExtrusion <> nil then
        begin
          entityExtrusion._Release;
          iunkn := IUnknown( entityExtrusion.GetDefinition() );
          // Интерфейс базовой операции выдавливания
//          iunkn.QueryInterface( IID_IBaseExtrusionDefinition, extrusionDefinition );
          extrusionDefinition := iunkn As IBossExtrusionDefinition;
          if extrusionDefinition <> nil then
          begin
            iunkn._Release;
            // Установка параметров операции выдавливания
            extrusionDefinition.SetDirectionType( dtNormal );     // Направление выдавливания ( dtNormal	- прямое
                                                                   // направление, для тонкой стенки - наружу,
                                                                   // dtReverse	- обратное направление, для тонкой стенки - внутрь
                                                                   // dtBoth - в обе стороны, dtMiddlePlane от средней плоскости )
            // Изменить параметры выдавливания в одном направлении
            extrusionDefinition.SetSideParam( 1,               // Направление выдавливания ( TRUE - прямое направление,
                                                                   // FALSE - обратное направление )
                                               etBlind,            // Тип выдавливания ( etBlind - строго на глубину,
                                                                   // etThroughAll - через всю деталь, etUpToVertexTo - на расстояние до вершины,
                                                                   // etUpToVertexFrom - на расстояние за вершину, etUpToSurfaceTo - на
                                                                   // расстояние до поверхности, etUpToSurfaceFrom - на расстояние за поверхность,
                                                                   // etUpToNearSurface	- до ближайшей поверхности )
                                               100,                // Глубина выдавливания
                                               0,                  // Угол уклона
                                               1 );             // Направление уклона ( TRUE - уклон наружу, FALSE - уклон внутрь )
            // Изменить параметры тонкой стенки
            extrusionDefinition.SetThinParam(  0,              // Признак тонкостенной операции
                                               dtBoth,             // Направление построения тонкой стенки
                                               10,                 // Толщина стенки в прямом направлении
                                               10 );               // Толщина стенки в обратном направлении
            extrusionDefinition.SetSketch( entitySketch );        // Эскиз операции выдавливания
            entityExtrusion.SetName( WideString('Операция - Кубик') );

            // Создать операцию выдавливания
            Result := entityExtrusion.Create() <> 0;
          end
        end
      end
    end
  end
end;

//-----------------------------------------------------------------------------
//
// ---
procedure TestOpenGL();
var
  komDoc        : IKompasDocument;
  docFrames     : IDocumentFrames;
  documentFrame : IDocumentFrame;
  doc3D         : IDocument3D;
  part          : IPart;
begin
  doc3D := IDocument3D( ksGet3dDocument() );
  if doc3D <> nil then
  begin
    doc3D._Release;
    doc3D.Create( 0, 1 ); // Создаем документ модель
    doc3D.SetDrawMode( vm_Shaded );
    doc3D.SetShadedWireframe( 1 );
    part := IPart( doc3D.GetPart( pTop_Part ) );
    if part <> nil then
    begin
      part._Release;
      if CreateExtrusion( part ) then
      begin
        part.SetName( WideString('Кубик') );
        part.Update();
        GetNewKompasAPI();
        if newKompasAPI <> nil then
        begin
          komDoc := newKompasAPI.ActiveDocument;
          if komDoc <> nil then
          begin
            docFrames := komDoc.DocumentFrames;
            if docFrames <> nil then
            begin
              documentFrame := docFrames.Item[0];
              if documentFrame <> nil then
              begin
	              NewDocumentFrameEvent( documentFrame, komDoc.Reference, 0 );
                documentFrame.SetGabaritModifying();
                documentFrame.RefreshWindow();
              end
            end
          end
        end
      end
    end
  end
end;

//-----------------------------------------------------------------------------
//
// ---
procedure TestOpenGLForCurrentDoc( regrawType : Integer );
var
  komDoc        : IKompasDocument;
  docFrames     : IDocumentFrames;
  documentFrame : IDocumentFrame;
begin
  GetNewKompasAPI();
  if newKompasAPI <> nil then
  begin
    komDoc := newKompasAPI.ActiveDocument;
    if komDoc <> nil then
    begin
      docFrames := komDoc.DocumentFrames;
      if docFrames <> nil then
      begin
        documentFrame := docFrames.Item[0];
        if documentFrame <> nil then
        begin
	        NewDocumentFrameEvent( documentFrame, komDoc.Reference, regrawType );
          documentFrame.SetGabaritModifying();
          documentFrame.RefreshWindow();
        end
      end
    end
  end
end;


end.


