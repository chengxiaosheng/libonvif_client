#include "onvif_demo_custom_types.h"

namespace onvif_demo {

void CustomSearchClient::GetEventSearchResultsCustom(
    const libonvif_client::tse_GetEventSearchResults& request,
    libonvif_client::OnvifCallback<demo_GetEventSearchResultsResponse> callback) {
    call_service<libonvif_client::tse_GetEventSearchResults, demo_GetEventSearchResultsResponse>(
        "http://www.onvif.org/ver10/search/wsdl/GetEventSearchResults",
        request, "GetEventSearchResults", "GetEventSearchResultsResponse",
        std::move(callback));
}

} // namespace onvif_demo