// template <class T> 
// T playAnimation(T objToAnimate, float currentTime, AnimTypes animationType, Vector2 destination, float radius) {
//     if (!objToAnimate.tweenActive) {
//         // Check if the object is within the specified radius of the destination point.
//         float distance = sqrt(pow(objToAnimate.xy.x - destination.x, 2) + pow(objToAnimate.xy.y - destination.y, 2));
//         if (distance <= radius) {
//             objToAnimate.tweenActive = true;
//         }
//     }

//     if (objToAnimate.tweenActive) {
//         switch (animationType) {
//             case EaseIn:
//                 objToAnimate.xy = easeInApply({10, 10}, {destination.x, destination.y}, currentTime);
//                 break;
//             case EaseOut:
//                 objToAnimate.xy = easeOutApply({10, 30}, {destination.x, destination.y}, currentTime);
//                 break;
//             default:
//                 break;
//         }
//     }

//     return objToAnimate;
// }
