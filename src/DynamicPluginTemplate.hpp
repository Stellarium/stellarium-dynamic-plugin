/*
 * Copyright (C) 2007 Fabien Chereau
 * Copyright (C) 2015 Kirill Snezhko
 * Copyright (C) 2018 Alexander Wolf
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Suite 500, Boston, MA  02110-1335, USA.
 */

#ifndef DYNAMICPLUGINTEMPLATE_HPP
#define DYNAMICPLUGINTEMPLATE_HPP

#include "StelModule.hpp"
#include "MarkerMgr.hpp"
#include <QFont>

class DynamicPluginTemplateWindow; 

//! This is an example of a plug-in which can be dynamically loaded into stellarium
class DynamicPluginTemplate : public StelModule
{
	Q_OBJECT
public:
	DynamicPluginTemplate();
	~DynamicPluginTemplate();

	///////////////////////////////////////////////////////////////////////////
	// Methods defined in the StelModule class
	virtual void init();
	virtual void deinit();
	virtual void update(double) {;}
	virtual void draw(StelCore* core);
	virtual double getCallOrder(StelModuleActionName actionName) const;
	virtual bool configureGui(bool show);
private:
	// Font used for displaying our text
	QFont font;
	DynamicPluginTemplateWindow * mainWindow;
	MarkerMgr* markerMgr;
};


#include <QObject>
#include "StelPluginInterface.hpp"

//! This class is used by Qt to manage a plug-in interface
class DynamicPluginTemplatePluginInterface : public QObject, public StelPluginInterface
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID StelPluginInterface_iid)
	Q_INTERFACES(StelPluginInterface)
public:
	virtual StelModule* getStelModule() const;
	virtual StelPluginInfo getPluginInfo() const;
	virtual QObjectList getExtensionList() const { return QObjectList(); }
};

#endif // DYNAMICPLUGINTEMPLATE_HPP
