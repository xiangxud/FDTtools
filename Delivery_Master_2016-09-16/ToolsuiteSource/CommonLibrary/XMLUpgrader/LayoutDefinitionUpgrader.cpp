#include "LayoutDefinitionUpgrader.h"

#include <QStringList>
#include <QDomDocument>
#include <QTextStream>

LayoutDefinitionUpgrader::LayoutDefinitionUpgrader(QString filePath, VersionNumber fromVersion, VersionNumber toVersion) :
    XMLUpgraderBase("LayoutDefinition", filePath, fromVersion, toVersion)
{
    populateUpgradeSteps();
}

void LayoutDefinitionUpgrader::populateUpgradeSteps()
{
    /* Add function steps */

}

bool LayoutDefinitionUpgrader::runStep(VersionNumber version)
{
    if(m_upgradeSteps.value(version, QPair<VersionStepFunction,QString>()) != QPair<VersionStepFunction,QString>())
    {
        return (*this.*m_upgradeSteps.value(version).first)();
    }
    else
    {
        return true;
    }
}

const QString LayoutDefinitionUpgrader::generateVersionInfo(VersionNumber version) const
{
    if (m_upgradeSteps.contains(version))
    {
        return m_upgradeSteps.value(version).second;
    }
    else
    {
        return QString("No upgrades for version %1.").arg(version.GetVersion());
    }
}

/**
 * UPGRADE & UPGRADE INFORMATION STEPS BELOW
 */
