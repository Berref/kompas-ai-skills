
function OnFinish(selProj, selObj)
{
	try
	{
		var strProjectPath = wizard.FindSymbol('PROJECT_PATH');
		var strProjectName = wizard.FindSymbol('PROJECT_NAME');

		selProj = CreateCustomProject(strProjectName, strProjectPath);
		//AddConfig(selProj, strProjectName);
		AddFilters(selProj);

		var InfFile = CreateCustomInfFile();
		AddFilesToCustomProj(selProj, strProjectName, strProjectPath, InfFile);
		AddConfig(selProj, strProjectName);
		PchSettings(selProj);
		InfFile.Delete();

		selProj.Object.Save();
	}
	catch(e)
	{
		if (e.description.length != 0)
			SetErrorInfo(e);
		return e.number
	}
}

function CreateCustomProject(strProjectName, strProjectPath)
{
	try
	{
		var strProjTemplatePath = wizard.FindSymbol('PROJECT_TEMPLATE_PATH');
		var strProjTemplate = '';
		strProjTemplate = strProjTemplatePath + '\\default.vcxproj';

		var Solution = dte.Solution;
		var strSolutionName = "";
		if (wizard.FindSymbol("CLOSE_SOLUTION"))
		{
			Solution.Close();
			strSolutionName = wizard.FindSymbol("VS_SOLUTION_NAME");
			if (strSolutionName.length)
			{
				var strSolutionPath = strProjectPath.substr(0, strProjectPath.length - strProjectName.length);
				Solution.Create(strSolutionPath, strSolutionName);
			}
		}

		var strProjectNameWithExt = '';
		strProjectNameWithExt = strProjectName + '.vcxproj';

		var oTarget = wizard.FindSymbol("TARGET");
		var prj;
		if (wizard.FindSymbol("WIZARD_TYPE") == vsWizardAddSubProject)  // vsWizardAddSubProject
		{
			var prjItem = oTarget.AddFromTemplate(strProjTemplate, strProjectNameWithExt);
			prj = prjItem.SubProject;
		}
		else
		{
			prj = oTarget.AddFromTemplate(strProjTemplate, strProjectPath, strProjectNameWithExt);
		}
		return prj;
	}
	catch(e)
	{
		throw e;
	}
}

function AddFilters(proj)
{
	try
	{
		// Add the folders to your project
		var group = proj.Object.AddFilter('Source Files');
		group.Filter = "cpp;c;cc;cxx;def;odl;idl;hpj;bat;asm;asmx;rc";
		group = proj.Object.AddFilter('Header Files');
		group.Filter = "h;hpp;hxx;hm;inl;inc;xsd";
		group = proj.Object.AddFilter('Resource Files');
		group.Filter = "rc;ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe;resx;tiff;tif;png;wav";
	}
	catch(e)
	{
		throw e;
	}
}

function AddConfig(proj, strProjectName)
{
	try
	{
		var config = proj.Object.Configurations('Debug');
		//config.IntermediateDirectory = '.\\Debug';
		//config.OutputDirectory = '.\\Debug';
		config.CharacterSet = charSetUNICODE;
		config.UseOfMFC = useMfcDynamic;
		config.ConfigurationType = typeDynamicLibrary;

		var CLTool = config.Tools('VCCLCompilerTool');
		var strDefines = CLTool.PreprocessorDefinitions;
		strDefines += "WIN32;_DEBUG;_WINDOWS;_WIN32_WINNT=0x0502";
		CLTool.PreprocessorDefinitions = strDefines;
		CLTool.AdditionalIncludeDirectories = "..\\..\\..\\include";
		CLTool.RuntimeLibrary = rtMultiThreadedDebugDLL;
		CLTool.UsePrecompiledHeader = pchUseUsingSpecific;
		CLTool.DebugInformationFormat = debugEditAndContinue;
		CLTool.Optimization = optimizeDisabled;
		
		var files = proj.Object.Files;
		var file = files("StdAfx.cpp");
		var fileConfig = file.FileConfigurations(config.Name);
		fileConfig.Tool.UsePrecompiledHeader = pchCreateUsingSpecific;

		var LinkTool = config.Tools('VCLinkerTool');
		LinkTool.AdditionalLibraryDirectories = "..\\..\\..\\lib";
		LinkTool.AdditionalDependencies = "kApi2D5.lib";
		LinkTool.GenerateDebugInformation = true;
		
		var uses3D = wizard.FindSymbol('USES_3D');
		var autoApi = wizard.FindSymbol('AUTO_API')
		if ( uses3D && !autoApi )
		  LinkTool.AdditionalDependencies += " kApi3D5.lib";
		  
		LinkTool.OutputFile = "..\\" + strProjectName + ".rtw";
		LinkTool.ModuleDefinitionFile = strProjectName + ".def";

		config = proj.Object.Configurations('Release');
		//config.IntermediateDirectory = '.\\Release';
		//config.OutputDirectory = '.\\Release';
		config.CharacterSet = charSetUNICODE;
		config.UseOfMFC = useMfcDynamic;
		config.ConfigurationType = typeDynamicLibrary;

		var CLTool = config.Tools('VCCLCompilerTool');
		var strDefines = CLTool.PreprocessorDefinitions;
		strDefines += "WIN32;_DEBUG;_WINDOWS;_WIN32_WINNT=0x0502";
		CLTool.PreprocessorDefinitions = strDefines;
		CLTool.AdditionalIncludeDirectories = "..\\..\\..\\include";
		CLTool.RuntimeLibrary = rtMultiThreadedDLL;
		CLTool.UsePrecompiledHeader = pchUseUsingSpecific;
		
		var files = proj.Object.Files;
		var file = files("StdAfx.cpp");
		var fileConfig = file.FileConfigurations(config.Name);
		fileConfig.Tool.UsePrecompiledHeader = pchCreateUsingSpecific;

		var LinkTool = config.Tools('VCLinkerTool');
		LinkTool.AdditionalLibraryDirectories = "..\\..\\..\\lib";
		LinkTool.AdditionalDependencies = "kApi2D5.lib";
		
		if ( uses3D && !autoApi )
		  LinkTool.AdditionalDependencies += " kApi3D5.lib";
		  
		LinkTool.OutputFile = "..\\" + strProjectName + ".rtw";
		LinkTool.ModuleDefinitionFile = strProjectName + ".def";
	}
	catch(e)
	{
		throw e;
	}
}

function PchSettings(proj)
{
	// TODO: specify pch settings
}

function DelFile(fso, strWizTempFile)
{
	try
	{
		if (fso.FileExists(strWizTempFile))
		{
			var tmpFile = fso.GetFile(strWizTempFile);
			tmpFile.Delete();
		}
	}
	catch(e)
	{
		throw e;
	}
}

function CreateCustomInfFile()
{
	try
	{
		var fso, TemplatesFolder, TemplateFiles, strTemplate;
		fso = new ActiveXObject('Scripting.FileSystemObject');

		var TemporaryFolder = 2;
		var tfolder = fso.GetSpecialFolder(TemporaryFolder);
		var strTempFolder = tfolder.Drive + '\\' + tfolder.Name;

		var strWizTempFile = strTempFolder + "\\" + fso.GetTempName();

		var strTemplatePath = wizard.FindSymbol('TEMPLATES_PATH');
		var strInfFile = strTemplatePath + '\\Templates.inf';
		wizard.RenderTemplate(strInfFile, strWizTempFile);

		var WizTempFile = fso.GetFile(strWizTempFile);
		return WizTempFile;
	}
	catch(e)
	{
		throw e;
	}
}

function GetTargetName(strName, strProjectName)
{
	try
	{
		// TODO: set the name of the rendered file based on the template filename
		var strTarget = strName;
    
    switch ( strName )
    {
      case 'root.cpp':
        strTarget = strProjectName + '.cpp';
        break;
        
      case 'root.h':
        strTarget = strProjectName + '.h';
        break;
        
      case 'root.def':
        strTarget = strProjectName + '.def';
        break;
        
      case 'root.rc':
        strTarget = strProjectName + '.rc';
        break;
        
      case 'root.rc2':
        strTarget = 'res\\' + strProjectName + '.rc2';
        break;
        
      case 'bar1.ico':
        strTarget = 'res\\' + strName;
        break;
      
      case 'root.bmp':
        strTarget = 'res\\bmp16\\1001.bmp';
        break;
        
      case 'root24.bmp':
        strTarget = 'res\\bmp24\\2001.bmp';
        break;
        
      case 'root32.bmp':
        strTarget = 'res\\bmp32\\3001.bmp';
        break;
        
      case 'root48.bmp':
        strTarget = 'res\\bmp48\\4001.bmp';
        break;
      
      case 'root.dic':
        strTarget = strProjectName + '.dic';
        break;
        
      case 'PropManager\\CPropMen.cpp':
      case 'PropManager\\CPropMen.h':
        strTarget = strName;
        break;
      
      case 'events\\COM\\CBaseEvent.cpp':
        strTarget = 'events\\CBaseEvent.cpp';
        break;
        
      case 'events\\COM\\CBaseEvent.h':
        strTarget = 'events\\CBaseEvent.h';
        break;
        
      case 'events\\COM\\ApplicationEvent.cpp':
        strTarget = 'events\\ApplicationEvent.cpp';
        break;
          
      case 'events\\COM\\ApplicationEvent.h':
        strTarget = 'events\\ApplicationEvent.h';
        break;
        
      case 'events\\COM\\DocumentEvent.cpp':
        strTarget = 'events\\DocumentEvent.cpp';
        break; 
           
      case 'events\\COM\\DocumentEvent.h':
        strTarget = 'events\\DocumentEvent.h';
        break;
        
      case 'events\\COM\\Document2DEvent.cpp':
        strTarget = 'events\\Document2DEvent.cpp';
        break; 
           
      case 'events\\COM\\Document2DEvent.h':
        strTarget = 'events\\Document2DEvent.h';
        break;
        
      case 'events\\COM\\Document3DEvent.cpp':
        strTarget = 'events\\Document3DEvent.cpp';
        break; 
           
      case 'events\\COM\\Document3DEvent.h':
        strTarget = 'events\\Document3DEvent.h';
        break;
        
      case 'events\\COM\\Object2DEvent.cpp':
        strTarget = 'events\\Object2DEvent.cpp';
        break; 
           
      case 'events\\COM\\Object2DEvent.h':
        strTarget = 'events\\Object2DEvent.h';
        break; 
           
      case 'events\\COM\\Object3DEvent.cpp':
        strTarget = 'events\\Object3DEvent.cpp';
        break; 
           
      case 'events\\COM\\Object3DEvent.h':
        strTarget = 'events\\Object3DEvent.h';
        break; 
        
      case 'events\\COM\\SelectMngEvent.cpp':
        strTarget = 'events\\SelectMngEvent.cpp';
        break; 
           
      case 'events\\COM\\SelectMngEvent.h':
        strTarget = 'events\\SelectMngEvent.h';
        break;  
      
      case 'events\\COM\\StampEvent.cpp':
        strTarget = 'events\\StampEvent.cpp';
        break; 
           
      case 'events\\COM\\StampEvent.h':
        strTarget = 'events\\StampEvent.h';
        break; 
        
      case 'events\\COM\\SpcObjectEvent.cpp':
        strTarget = 'events\\SpcObjectEvent.cpp';
        break; 
           
      case 'events\\COM\\SpcObjectEvent.h':
        strTarget = 'events\\SpcObjectEvent.h';
        break;
        
      case 'events\\COM\\SpecificationEvent.cpp':
        strTarget = 'events\\SpecificationEvent.cpp';
        break; 
           
      case 'events\\COM\\SpecificationEvent.h':
        strTarget = 'events\\SpecificationEvent.h';
        break;
        
      case 'events\\COM\\SpcDocumentEvent.cpp':
        strTarget = 'events\\SpcDocumentEvent.cpp';
        break; 
           
      case 'events\\COM\\SpcDocumentEvent.h':
        strTarget = 'events\\SpcDocumentEvent.h';
        break;
      
      case 'events\\COM\\DocumentFrameEvent.cpp':
        strTarget = 'events\\DocumentFrameEvent.cpp';
        break; 
           
      case 'events\\COM\\DocumentFrameEvent.h':
        strTarget = 'events\\DocumentFrameEvent.h';
        break;
      
      case 'events\\COM\\ViewsAndLayersEvent.cpp':
        strTarget = 'events\\ViewsAndLayersEvent.cpp';
        break; 
           
      case 'events\\COM\\ViewsAndLayersEvent.h':
        strTarget = 'events\\ViewsAndLayersEvent.h';
        break;
      
      case 'events\\COM\\LibMngEvent.cpp':
        strTarget = 'events\\LibMngEvent.cpp';
        break; 
           
      case 'events\\COM\\LibMngEvent.h':
        strTarget = 'events\\LibMngEvent.h';
        break;
      
      case 'events\\COM\\PropUserEvent.cpp':
        strTarget = 'events\\PropUserEvent.cpp';
        break;
          
      case 'events\\COM\\PropUserEvent.h':
        strTarget = 'events\\PropUserEvent.h';
        break;
                  
      case 'events\\AUTO\\ABaseEvent.cpp':
        strTarget = 'events\\ABaseEvent.cpp';
        break;
        
      case 'events\\AUTO\\ABaseEvent.h':
        strTarget = 'events\\ABaseEvent.h';
        break;
        
      case 'events\\AUTO\\Misc.h':
        strTarget = 'events\\Misc.h';
        break;
        
      case 'events\\AUTO\\Misc.cpp':
        strTarget = 'events\\Misc.cpp';
        break;
      
      case 'events\\AUTO\\ApplicationEvent.h':
        strTarget = 'events\\ApplicationEvent.h';
        break;
          
      case 'events\\AUTO\\ApplicationEvent.cpp':
        strTarget = 'events\\ApplicationEvent.cpp';
        break;
        
      case 'events\\AUTO\\DocumentEvent.h':
        strTarget = 'events\\DocumentEvent.h';
        break;
          
      case 'events\\AUTO\\DocumentEvent.cpp':
        strTarget = 'events\\DocumentEvent.cpp';
        break;
        
      case 'events\\AUTO\\Document2DEvent.h':
        strTarget = 'events\\Document2DEvent.h';
        break;
          
      case 'events\\AUTO\\Document2DEvent.cpp':
        strTarget = 'events\\Document2DEvent.cpp';
        break;
        
      case 'events\\AUTO\\Document3DEvent.h':
        strTarget = 'events\\Document3DEvent.h';
        break;
          
      case 'events\\AUTO\\Document3DEvent.cpp':
        strTarget = 'events\\Document3DEvent.cpp';
        break;
      
      case 'events\\AUTO\\Object2DEvent.h':
        strTarget = 'events\\Object2DEvent.h';
        break;
          
      case 'events\\AUTO\\Object2DEvent.cpp':
        strTarget = 'events\\Object2DEvent.cpp';
        break;
        
      case 'events\\AUTO\\Object3DEvent.h':
        strTarget = 'events\\Object3DEvent.h';
        break;
          
      case 'events\\AUTO\\Object3DEvent.cpp':
        strTarget = 'events\\Object3DEvent.cpp';
        break; 
        
      case 'events\\AUTO\\SelectMngEvent.h':
        strTarget = 'events\\SelectMngEvent.h';
        break;
          
      case 'events\\AUTO\\SelectMngEvent.cpp':
        strTarget = 'events\\SelectMngEvent.cpp';
        break;
        
      case 'events\\AUTO\\StampEvent.h':
        strTarget = 'events\\StampEvent.h';
        break;
          
      case 'events\\AUTO\\StampEvent.cpp':
        strTarget = 'events\\StampEvent.cpp';
        break;  
      
      case 'events\\AUTO\\SpcObjectEvent.h':
        strTarget = 'events\\SpcObjectEvent.h';
        break;
          
      case 'events\\AUTO\\SpcObjectEvent.cpp':
        strTarget = 'events\\SpcObjectEvent.cpp';
        break;
        
      case 'events\\AUTO\\SpecificationEvent.h':
        strTarget = 'events\\SpecificationEvent.h';
        break;
          
      case 'events\\AUTO\\SpecificationEvent.cpp':
        strTarget = 'events\\SpecificationEvent.cpp';
        break;  
      
      case 'events\\AUTO\\SpcDocumentEvent.h':
        strTarget = 'events\\SpcDocumentEvent.h';
        break;
          
      case 'events\\AUTO\\SpcDocumentEvent.cpp':
        strTarget = 'events\\SpcDocumentEvent.cpp';
        break;
      
      case 'events\\AUTO\\DocumentFrameEvent.h':
        strTarget = 'events\\DocumentFrameEvent.h';
        break;
          
      case 'events\\AUTO\\DocumentFrameEvent.cpp':
        strTarget = 'events\\DocumentFrameEvent.cpp';
        break;
      
      case 'events\\AUTO\\ViewsAndLayersEvent.h':
        strTarget = 'events\\ViewsAndLayersEvent.h';
        break;
          
      case 'events\\AUTO\\ViewsAndLayersEvent.cpp':
        strTarget = 'events\\ViewsAndLayersEvent.cpp';
        break;
      
      case 'events\\AUTO\\LibMngEvent.h':
        strTarget = 'events\\LibMngEvent.h';
        break;
          
      case 'events\\AUTO\\LibMngEvent.cpp':
        strTarget = 'events\\LibMngEvent.cpp';
        break;
      
      case 'events\\AUTO\\PropUserEvent.h':
        strTarget = 'events\\PropUserEvent.h';
        break;
          
      case 'events\\AUTO\\PropUserEvent.cpp':
        strTarget = 'events\\PropUserEvent.cpp';
        break;
                    
      default:
        break;
    }
        
		return strTarget; 
	}
	catch(e)
	{
		throw e;
	}
}

function AddFilesToCustomProj(proj, strProjectName, strProjectPath, InfFile)
{
	try
	{
		var projItems = proj.ProjectItems

		var strTemplatePath = wizard.FindSymbol('TEMPLATES_PATH');

		var strTpl = '';
		var strName = '';

		var strTextStream = InfFile.OpenAsTextStream(1, -2);
		while (!strTextStream.AtEndOfStream)
		{
			strTpl = strTextStream.ReadLine();
			if (strTpl != '')
			{
				strName = strTpl;
				var strTarget = GetTargetName(strName, strProjectName);
				var strTemplate = strTemplatePath + '\\' + strTpl;
				var strFile = strProjectPath + '\\' + strTarget;

				var bCopyOnly = false;  //"true" will only copy the file from strTemplate to strTarget without rendering/adding to the project
				var strExt = strName.substr(strName.lastIndexOf("."));
				if(strExt==".bmp" || strExt==".ico" || strExt==".gif" || strExt==".rtf" || strExt==".css")
					bCopyOnly = true;
				wizard.RenderTemplate(strTemplate, strFile, bCopyOnly);
				proj.Object.AddFile(strFile);
			}
		}
		strTextStream.Close();
	}
	catch(e)
	{
		throw e;
	}
}
