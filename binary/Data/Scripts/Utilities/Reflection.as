class Reflection : ScriptObject
{
    private Node@ reflectionCameraNode;
float height = 1.0f;

void Start()
{
    // Create a mathematical plane to represent the water in calculations
    Plane waterPlane(Vector3(0.0f, 1.0f, 0.0f), Vector3(0,height,0));
    // Create a downward biased plane for reflection view clipping. Biasing is necessary to avoid too aggressive clipping
    Plane waterClipPlane(Vector3(0.0f, 1.0f, 0.0f), Vector3(0.0f, height - 0.1f, 0.0f));

    // Create camera for water reflection
    // It will have the same farclip and position as the main viewport camera, but uses a reflection plane to modify
    // its position when rendering
    reflectionCameraNode = node.CreateChild();
    Camera@ reflectionCamera = reflectionCameraNode.CreateComponent("Camera");
    reflectionCamera.farClip = 750.0;
	reflectionCamera.fov     = 90.0;ff
    reflectionCamera.viewMask = 0x7fffffff; // Hide objects with only bit 31 in the viewmask (the water plane)
    reflectionCamera.autoAspectRatio = false;
    reflectionCamera.useReflection = true;
    reflectionCamera.reflectionPlane = waterPlane;
    reflectionCamera.useClipping = true; // Enable clipping of geometry behind water plane
    reflectionCamera.clipPlane = waterClipPlane;
    // The water reflection texture is rectangular. Set reflection camera aspect ratio to match
    reflectionCamera.aspectRatio = float(graphics.width) / float(graphics.height);

    // Create a texture and setup viewport for water reflection. Assign the reflection texture to the diffuse
    // texture unit of the water material
    int texSize = 1024;
    Texture2D@ renderTexture = Texture2D();
    renderTexture.SetSize(texSize, texSize, GetRGBFormat(), TEXTURE_RENDERTARGET);
    renderTexture.filterMode = FILTER_BILINEAR;
    RenderSurface@ surface = renderTexture.renderSurface;
    Viewport@ rttViewport = Viewport(scene, reflectionCamera);
    surface.viewports[0] = rttViewport;
    Material@ waterMat = cache.GetResource("Material", "Materials/Water.xml");
    waterMat.textures[TU_DIFFUSE] = renderTexture;
}
}