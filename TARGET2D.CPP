#include "Graphics.H"

RenderTarget2D::RenderTarget2D(IGraphicsDevice *pDevice, float width, float height)
{
    m_pDevice = pDevice;
    m_width = width;
    m_height = height;
    m_deviceWidth = m_pDevice->GetDeviceWidth();
    m_deviceHeight = m_pDevice->GetDeviceHeight();
}

float RenderTarget2D::GetTargetWidth() const
{
    return m_width;
}

float RenderTarget2D::GetTargetHeight() const
{
    return m_height;
}

int RenderTarget2D::vRenderSpaceToDeviceSpace(float renderSpace) const 
{
	return (int)((1.0 - (renderSpace / m_height)) * m_deviceHeight);
}

int RenderTarget2D::hRenderSpaceToDeviceSpace(float renderSpace) const
{
    return (int)(renderSpace / m_width * m_deviceWidth);
}

void RenderTarget2D::Put(const vec2d &a, unsigned char color)
{
    m_pDevice->PutPixel(hRenderSpaceToDeviceSpace(a.x), vRenderSpaceToDeviceSpace(a.y), color);
}

void RenderTarget2D::PutLine(const vec2d &a, const vec2d &b, unsigned char color)
{
    m_pDevice->PutLine(
        hRenderSpaceToDeviceSpace(a.x),
        vRenderSpaceToDeviceSpace(a.y),
        hRenderSpaceToDeviceSpace(b.x),
        vRenderSpaceToDeviceSpace(b.y),
        color
    );
}

